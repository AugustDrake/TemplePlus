from toee import *
import char_class_utils
import char_editor
import tpdp
import functools

# Warrior:  Dungeon Master's Guide

###################################################

def GetConditionName(): # used by API
	return "Warrior"

def GetCategory():
	return "Dungeon Master's Guide"

def GetClassDefinitionFlags():
	return CDF_BaseClass

def GetClassHelpTopic():
	return "TAG_WARRIORS"
	
classEnum = stat_level_warrior

###################################################

class_feats = {
1: (feat_armor_proficiency_light, feat_armor_proficiency_medium, feat_armor_proficiency_heavy, feat_shield_proficiency, feat_tower_shield_proficiency, feat_simple_weapon_proficiency, feat_martial_weapon_proficiency_all),
}

class_skills = (skill_climb, skill_handle_animal, skill_intimidate, skill_jump, skill_ride, skill_swim)


def IsEnabled():
	return 1

def GetDeityClass():
	return stat_level_fighter

def GetHitDieType():
	return 8
	
def GetSkillPtsPerLevel():
	return 2
	
def GetBabProgression():
	return base_attack_bonus_type_martial
	
def IsFortSaveFavored():
	return 1
	
def IsRefSaveFavored():
	return 0
	
def IsWillSaveFavored():
	return 0

def GetSpellListType():
	return spell_list_type_none

def IsClassSkill(skillEnum):
	return char_class_utils.IsClassSkill(class_skills, skillEnum)

def IsClassFeat(featEnum):
	return char_class_utils.IsClassFeat(class_feats, featEnum)

def GetClassFeats():
	return class_feats
	
def IsAlignmentCompatible( alignment):
	return 1

def ObjMeetsPrereqs( obj ):
	return 1
	
def IsSelectingFeatsOnLevelup( obj ):
	return 0
	
def LevelupGetBonusFeats( obj ):
	return
	
def LevelupSpellsFinalize( obj, classLvlNew = -1 ):
	return 0
