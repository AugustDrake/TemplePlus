from toee import *
import char_class_utils
import char_editor
import tpdp
import functools

# Expert:  Dungeon Master's Guide

###################################################

def GetConditionName(): # used by API
	return "Expert"

def GetCategory():
	return "Dungeon Master's Guide"

def GetClassDefinitionFlags():
	return CDF_BaseClass

def GetClassHelpTopic():
	return "TAG_EXPERTS"
	
classEnum = stat_level_expert

###################################################

class_feats = {
1: (feat_armor_proficiency_light, feat_simple_weapon_proficiency),
}

class_skills = (skill_alchemy, skill_appraise, skill_balance, skill_bluff, skill_climb, skill_concentration, skill_craft, skill_decipher_script, skill_diplomacy, skill_disable_device, skill_disguise, skill_escape_artist, skill_forgery, skill_gather_information, skill_hide, skill_intimidate, skill_jump, skill_listen, skill_move_silently, skill_open_lock, skill_perform, skill_profession, skill_search, skill_sense_motive, skill_pick_pocket, skill_spot, skill_swim, skill_tumble, skill_use_magic_device, skill_use_rope)


def IsEnabled():
	return 1

def GetDeityClass():
	return stat_level_fighter

def GetHitDieType():
	return 6
	
def GetSkillPtsPerLevel():
	return 6
	
def GetBabProgression():
	return base_attack_bonus_type_semi_martial
	
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
