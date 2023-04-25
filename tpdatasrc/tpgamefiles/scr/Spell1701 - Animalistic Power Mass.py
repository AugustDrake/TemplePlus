from toee import *

def OnBeginSpellCast( spell ):
	print "Animalistic Power Mass OnBeginSpellCast"
	print "spell.target_list=", spell.target_list
	print "spell.caster=", spell.caster, " caster.level= ", spell.caster_level

def	OnSpellEffect( spell ):
	print "Animalistic Power Mass OnSpellEffect"

    targetsToRemove = []
    spell.duration = 10 * spell.caster_level # 1 min/cl
	target_item = spell.target_list[0]

	animal_amount = 2
	
    for spellTarget in spell.target_list:
        targetIsFriendly = spellTarget.obj.is_friendly(spell.caster)
		if target_item.obj.is_friendly( spell.caster ):
			target_item.obj.condition_add_with_args( 'sp-Animalistic Power', spell.id, spell.duration, animal_amount )
			target_item.partsys_id = game.particles( 'sp-AnimalisticPower', target_item.obj )
		elif not target_item.obj.saving_throw_spell( spell.dc, D20_Save_Will, D20STD_F_NONE, spell.caster, spell.id ):
			# saving throw unsuccesful
			target_item.obj.float_mesfile_line( 'mes\\spell.mes', 30002 )
			target_item.obj.condition_add_with_args( 'sp-Animalistic Power', spell.id, spell.duration, animal_amount )
			target_item.partsys_id = game.particles( 'sp-AnimalisticPower', target_item.obj )
		else:
			# saving throw successful
			target_item.obj.float_mesfile_line( 'mes\\spell.mes', 30001 )
			game.particles( 'Fizzle', target_item.obj )
            targetsToRemove.append(spellTarget.obj)

    if targetsToRemove:
        spell.target_list.remove_list(targetsToRemove)

	spell.spell_end( spell.id )

def OnBeginRound( spell ):
	print "Animalistic Power Mass OnBeginRound"

def OnEndSpellCast( spell ):
	print "Animalistic Power Mass OnEndSpellCast"
	