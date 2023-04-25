from toee import *
import char_class_utils
import char_editor
import tpdp
import functools

# Commoner:  Dungeon Master's Guide

###################################################

def GetConditionName(): # used by API
	return "Commoner"

def GetCategory():
	return "Dungeon Master's Guide"

def GetClassDefinitionFlags():
	return CDF_BaseClass

def GetClassHelpTopic():
	return "TAG_COMMONERS"
	
classEnum = stat_level_commoner

###################################################

class_feats = {
1: (feat_simple_weapon_proficiency),
}

class_skills = (skill_climb, skill_craft, skill_handle_animal, skill_jump, skill_listen, skill_profession, skill_ride, skill_spot, skill_swim, skill_use_rope)


def IsEnabled():
	return 1

def GetDeityClass():
	return stat_level_fighter

def GetHitDieType():
	return 4
	
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
