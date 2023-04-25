from templeplus.pymod import PythonModifier
from toee import *
import tpdp
from utilities import *
import spell_utils

print "Registering sp-Animalistic Power"

def animalisticPowerSpellBonusToStat(attachee, args, evt_obj):
	bonusValue = 2 #+2 to whatever stat is being called
	bonusType = 12 #Enhancement Bonus
	evt_obj.bonus_list.add(bonusValue, bonusType, "~Animalistic Power~[TAG_SPELLS_ANIMALISTIC_POWER] ~Enhancement~[TAG_MODIFIER_ENHANCEMENT] Bonus")
	return 0
	
animalisticPowerSpell = PythonModifier("sp-Animalistic Power", 2) # spell_id, duration
animalisticPowerSpell.AddHook(ET_OnAbilityScoreLevel, EK_STAT_STRENGTH, animalisticPowerSpellBonusToStat,())
animalisticPowerSpell.AddHook(ET_OnAbilityScoreLevel, EK_STAT_DEXTERITY, animalisticPowerSpellBonusToStat,())
animalisticPowerSpell.AddHook(ET_OnAbilityScoreLevel, EK_STAT_CONSTITUTION, animalisticPowerSpellBonusToStat,())
animalisticPowerSpell.AddHook(ET_OnGetTooltip, EK_NONE, spell_utils.spellTooltip, ())
animalisticPowerSpell.AddHook(ET_OnGetEffectTooltip, EK_NONE, spell_utils.spellEffectTooltip, ())
animalisticPowerSpell.AddHook(ET_OnD20Query, EK_Q_Critter_Has_Spell_Active, spell_utils.queryActiveSpell, ())
animalisticPowerSpell.AddHook(ET_OnD20Signal, EK_S_Killed, spell_utils.spellKilled, ())
animalisticPowerSpell.AddSpellDispelCheckStandard()
animalisticPowerSpell.AddSpellTeleportPrepareStandard()
animalisticPowerSpell.AddSpellTeleportReconnectStandard()
animalisticPowerSpell.AddSpellCountdownStandardHook()