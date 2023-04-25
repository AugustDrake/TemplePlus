from toee import *
import char_class_utils
import char_editor
import tpdp
import functools

# Adept:  Dungeon Master's Guide

###################################################

def GetConditionName(): # used by API
	return "Adept"

# def GetSpellCasterConditionName():
	# return "Adept Spellcasting"
    
def GetCategory():
	return "Dungeon Master's Guide"

def GetClassDefinitionFlags():
	return CDF_BaseClass

def GetClassHelpTopic():
	return "TAG_ADEPTS"
	
classEnum = stat_level_adept

###################################################

class_feats = {
1: (feat_simple_weapon_proficiency),
2: (feat_call_familiar),
}

class_skills = (skill_concentration, skill_craft, skill_handle_animal, skill_heal, skill_knowledge_all, skill_profession, skill_spellcraft, skill_wilderness_lore)

spells_per_day = {
1:  (3, 1),
2:  (3, 1),
3:  (3, 2),
4:  (3, 2, 0),
5:  (3, 2, 1),
6:  (3, 2, 1),
7:  (3, 3, 2),
8:  (3, 3, 2, 0),
9:  (3, 3, 2, 1),
10: (3, 3, 2, 1),
11: (3, 3, 3, 2),
12: (3, 3, 3, 2, 0),
13: (3, 3, 3, 2, 1),
14: (3, 3, 3, 2, 1),
15: (3, 3, 3, 3, 2),
16: (3, 3, 3, 3, 2, 0),
17: (3, 3, 3, 3, 2, 1),
18: (3, 3, 3, 3, 2, 1),
19: (3, 3, 3, 3, 3, 2),
20: (3, 3, 3, 3, 3, 2)
}

# adept spell list
spell_list = {
	0: (spell_cure_minor_wounds, spell_detect_magic, spell_guidance, spell_read_magic, spell_touch_of_fatigue),
	1: (spell_bless, spell_burning_hands, spell_cause_fear, spell_command, spell_comprehend_languages, spell_cure_light_wounds, spell_detect_chaos, spell_detect_law, spell_detect_good, spell_detect_evil, spell_endure_elements, spell_obscuring_mist, spell_protection_from_chaos, spell_protection_from_law, spell_protection_from_good, spell_protection_from_evil, spell_sleep),
	2: (spell_aid, spell_animal_trance, spell_endurance, spell_bulls_strength, spell_cats_grace, spell_cure_moderate_wounds, spell_darkness, spell_delay_poison, spell_invisibility, spell_mirror_image, spell_scorching_ray, spell_see_invisibility, spell_web),
	3: (spell_animate_dead, spell_bestow_curse, spell_contagion, spell_continual_flame, spell_cure_serious_wounds, spell_daylight, spell_deeper_darkness, spell_lightning_bolt, spell_neutralize_poison, spell_remove_curse, spell_remove_disease, spell_tongues),
	4: (spell_cure_critical_wounds, spell_minor_creation, spell_polymorph_self, spell_restoration, spell_stoneskin, spell_wall_of_fire),
	5: (spell_polymorph_other, spell_break_enchantment, spell_commune, spell_heal, spell_major_creation, spell_raise_dead, spell_true_seeing, spell_wall_of_stone),
}


def IsEnabled():
	return 1

def GetDeityClass():
	return stat_level_fighter

def GetHitDieType():
	return 6
	
def GetSkillPtsPerLevel():
	return 2
	
def GetBabProgression():
	return base_attack_bonus_type_non_martial
	
def IsFortSaveFavored():
	return 1
	
def IsRefSaveFavored():
	return 0
	
def IsWillSaveFavored():
	return 0

# Spell casting
def GetSpellListType():
	return spell_list_type_special

def GetSpellSourceType():
	return spell_source_type_divine

def GetSpellReadyingType():
	return spell_readying_vancian

def GetSpellList():
	return spell_list

def GetSpellsPerDay():
	return spells_per_day

caster_levels = range(1, 21)
def GetCasterLevels():
	return caster_levels

def GetSpellDeterminingStat():
	return stat_wisdom
    
def GetSpellDcStat():
	return stat_wisdom

def IsClassSkill(skillEnum):
	return char_class_utils.IsClassSkill(class_skills, skillEnum)

def IsClassFeat(featEnum):
	return char_class_utils.IsClassFeat(class_feats, featEnum)

def GetClassFeats():
	return class_feats

def IsAlignmentCompatible( alignment):
	return 1

def ObjMeetsPrereqs( obj ):
	abScore = obj.stat_base_get(stat_wisdom)
	if abScore > 10:
		return 1
	return 0

def IsSelectingFeaturesOnLevelup( obj ):
	newLvl = obj.stat_level_get( classEnum ) + 1
	if newLvl == 1:
		return 1
	return 0

def LevelupSpellsFinalize( obj, classLvlNew = -1 ):
	classLvl = obj.stat_level_get(classEnum)
	if classLvlNew <= 0:
		classLvlNew = classLvl + 1

	maxSpellLvl = char_editor.get_max_spell_level( obj, classEnum, classLvlNew )
	class_spells = char_editor.get_learnable_spells(obj, classEnum, maxSpellLvl)
	char_editor.spell_known_add(class_spells)
	
	return 0