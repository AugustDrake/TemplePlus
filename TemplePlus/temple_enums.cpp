
#include "stdafx.h"
#include "temple_enums.h"

static const char *ObjFieldNames[] = {
	"obj_f_begin", // 0,
	"obj_f_location", // 1,
	"obj_f_offset_x", // 2,
	"obj_f_offset_y", // 3,
	"obj_f_2D_shadow_art", // 4,
	"obj_f_blit_flags", // 5,
	"obj_f_blit_color", // 6,
	"obj_f_transparency", // 7,
	"obj_f_model_scale", // 8,
	"obj_f_light_flags", // 9,
	"obj_f_light_material", // 10,
	"obj_f_light_color", // 11,
	"obj_f_light_radius", // 12,
	"obj_f_light_angle_start", // 13,
	"obj_f_light_angle_end", // 14,
	"obj_f_light_type", // 15,
	"obj_f_light_facing_X", // 16,
	"obj_f_light_facing_Y", // 17,
	"obj_f_light_facing_Z", // 18,
	"obj_f_light_offset_X", // 19,
	"obj_f_light_offset_Y", // 20,
	"obj_f_light_offset_Z", // 21,
	"obj_f_flags", // 22,
	"obj_f_spell_flags", // 23,
	"obj_f_name", // 24,
	"obj_f_description", // 25,
	"obj_f_size", // 26,
	"obj_f_hp_pts", // 27,
	"obj_f_hp_adj", // 28,
	"obj_f_hp_damage", // 29,
	"obj_f_material", // 30,
	"obj_f_scripts_idx", // 31,
	"obj_f_sound_effect", // 32,
	"obj_f_category", // 33,
	"obj_f_rotation", // 34,
	"obj_f_speed_walk", // 35,
	"obj_f_speed_run", // 36,
	"obj_f_base_mesh", // 37,
	"obj_f_base_anim", // 38,
	"obj_f_radius", // 39,
	"obj_f_3d_render_height", // 40,
	"obj_f_conditions", // 41,
	"obj_f_condition_arg0", // 42,
	"obj_f_permanent_mods", // 43,
	"obj_f_initiative", // 44,
	"obj_f_dispatcher", // 45,
	"obj_f_subinitiative", // 46,
	"obj_f_secretdoor_flags", // 47,
	"obj_f_secretdoor_effectname", // 48,
	"obj_f_secretdoor_dc", // 49,
	"obj_f_pad_i_7", // 50,
	"obj_f_pad_i_8", // 51,
	"obj_f_pad_i_9", // 52,
	"obj_f_pad_i_0", // 53,
	"obj_f_offset_z", // 54,
	"obj_f_rotation_pitch", // 55,
	"obj_f_pad_f_3", // 56,
	"obj_f_pad_f_4", // 57,
	"obj_f_pad_f_5", // 58,
	"obj_f_pad_f_6", // 59,
	"obj_f_pad_f_7", // 60,
	"obj_f_pad_f_8", // 61,
	"obj_f_pad_f_9", // 62,
	"obj_f_pad_f_0", // 63,
	"obj_f_pad_i64_0", // 64,
	"obj_f_pad_i64_1", // 65,
	"obj_f_pad_i64_2", // 66,
	"obj_f_pad_i64_3", // 67,
	"obj_f_pad_i64_4", // 68,
	"obj_f_last_hit_by", // 69,
	"obj_f_pad_obj_1", // 70,
	"obj_f_pad_obj_2", // 71,
	"obj_f_pad_obj_3", // 72,
	"obj_f_pad_obj_4", // 73,
	"obj_f_permanent_mod_data", // 74,
	"obj_f_attack_types_idx", // 75,
	"obj_f_attack_bonus_idx", // 76,
	"obj_f_strategy_state", // 77,
	"obj_f_pad_ias_4", // 78,
	"obj_f_pad_i64as_0", // 79,
	"obj_f_pad_i64as_1", // 80,
	"obj_f_pad_i64as_2", // 81,
	"obj_f_pad_i64as_3", // 82,
	"obj_f_pad_i64as_4", // 83,
	"obj_f_pad_objas_0", // 84,
	"obj_f_pad_objas_1", // 85,
	"obj_f_pad_objas_2", // 86,
	"obj_f_end", // 87,
	"obj_f_portal_begin", // 88,
	"obj_f_portal_flags", // 89,
	"obj_f_portal_lock_dc", // 90,
	"obj_f_portal_key_id", // 91,
	"obj_f_portal_notify_npc", // 92,
	"obj_f_portal_pad_i_1", // 93,
	"obj_f_portal_pad_i_2", // 94,
	"obj_f_portal_pad_i_3", // 95,
	"obj_f_portal_pad_i_4", // 96,
	"obj_f_portal_pad_i_5", // 97,
	"obj_f_portal_pad_obj_1", // 98,
	"obj_f_portal_pad_ias_1", // 99,
	"obj_f_portal_pad_i64as_1", // 100,
	"obj_f_portal_end", // 101,
	"obj_f_container_begin", // 102,
	"obj_f_container_flags", // 103,
	"obj_f_container_lock_dc", // 104,
	"obj_f_container_key_id", // 105,
	"obj_f_container_inventory_num", // 106,
	"obj_f_container_inventory_list_idx", // 107,
	"obj_f_container_inventory_source", // 108,
	"obj_f_container_notify_npc", // 109,
	"obj_f_container_pad_i_1", // 110,
	"obj_f_container_pad_i_2", // 111,
	"obj_f_container_pad_i_3", // 112,
	"obj_f_container_pad_i_4", // 113,
	"obj_f_container_pad_i_5", // 114,
	"obj_f_container_pad_obj_1", // 115,
	"obj_f_container_pad_obj_2", // 116,
	"obj_f_container_pad_ias_1", // 117,
	"obj_f_container_pad_i64as_1", // 118,
	"obj_f_container_pad_objas_1", // 119,
	"obj_f_container_end", // 120,
	"obj_f_scenery_begin", // 121,
	"obj_f_scenery_flags", // 122,
	"obj_f_scenery_pad_obj_0", // 123,
	"obj_f_scenery_respawn_delay", // 124,
	"obj_f_scenery_pad_i_0", // 125,
	"obj_f_scenery_pad_i_1", // 126,
	"obj_f_scenery_teleport_to", // 127,
	"obj_f_scenery_pad_i_4", // 128,
	"obj_f_scenery_pad_i_5", // 129,
	"obj_f_scenery_pad_obj_1", // 130,
	"obj_f_scenery_pad_ias_1", // 131,
	"obj_f_scenery_pad_i64as_1", // 132,
	"obj_f_scenery_end", // 133,
	"obj_f_projectile_begin", // 134,
	"obj_f_projectile_flags_combat", // 135,
	"obj_f_projectile_flags_combat_damage", // 136,
	"obj_f_projectile_parent_weapon", // 137,
	"obj_f_projectile_parent_ammo", // 138,
	"obj_f_projectile_part_sys_id", // 139,
	"obj_f_projectile_acceleration_x", // 140,
	"obj_f_projectile_acceleration_y", // 141,
	"obj_f_projectile_acceleration_z", // 142,
	"obj_f_projectile_pad_i_4", // 143,
	"obj_f_projectile_pad_obj_1", // 144,
	"obj_f_projectile_pad_obj_2", // 145,
	"obj_f_projectile_pad_obj_3", // 146,
	"obj_f_projectile_pad_ias_1", // 147,
	"obj_f_projectile_pad_i64as_1", // 148,
	"obj_f_projectile_pad_objas_1", // 149,
	"obj_f_projectile_end", // 150,
	"obj_f_item_begin", // 151,
	"obj_f_item_flags", // 152,
	"obj_f_item_parent", // 153,
	"obj_f_item_weight", // 154,
	"obj_f_item_worth", // 155,
	"obj_f_item_inv_aid", // 156,
	"obj_f_item_inv_location", // 157,
	"obj_f_item_ground_mesh", // 158,
	"obj_f_item_ground_anim", // 159,
	"obj_f_item_description_unknown", // 160,
	"obj_f_item_description_effects", // 161,
	"obj_f_item_spell_idx", // 162,
	"obj_f_item_spell_idx_flags", // 163,
	"obj_f_item_spell_charges_idx", // 164,
	"obj_f_item_ai_action", // 165,
	"obj_f_item_wear_flags", // 166,
	"obj_f_item_material_slot", // 167,
	"obj_f_item_quantity", // 168,
	"obj_f_item_pad_i_1", // 169,
	"obj_f_item_pad_i_2", // 170,
	"obj_f_item_pad_i_3", // 171,
	"obj_f_item_pad_i_4", // 172,
	"obj_f_item_pad_i_5", // 173,
	"obj_f_item_pad_i_6", // 174,
	"obj_f_item_pad_obj_1", // 175,
	"obj_f_item_pad_obj_2", // 176,
	"obj_f_item_pad_obj_3", // 177,
	"obj_f_item_pad_obj_4", // 178,
	"obj_f_item_pad_obj_5", // 179,
	"obj_f_item_pad_wielder_condition_array", // 180,
	"obj_f_item_pad_wielder_argument_array", // 181,
	"obj_f_item_pad_i64as_1", // 182,
	"obj_f_item_pad_i64as_2", // 183,
	"obj_f_item_pad_objas_1", // 184,
	"obj_f_item_pad_objas_2", // 185,
	"obj_f_item_end", // 186,
	"obj_f_weapon_begin", // 187,
	"obj_f_weapon_flags", // 188,
	"obj_f_weapon_range", // 189,
	"obj_f_weapon_ammo_type", // 190,
	"obj_f_weapon_ammo_consumption", // 191,
	"obj_f_weapon_missile_aid", // 192,
	"obj_f_weapon_crit_hit_chart", // 193,
	"obj_f_weapon_attacktype", // 194,
	"obj_f_weapon_damage_dice", // 195,
	"obj_f_weapon_animtype", // 196,
	"obj_f_weapon_type", // 197,
	"obj_f_weapon_crit_range", // 198,
	"obj_f_weapon_pad_i_1", // 199,
	"obj_f_weapon_pad_i_2", // 200,
	"obj_f_weapon_pad_obj_1", // 201,
	"obj_f_weapon_pad_obj_2", // 202,
	"obj_f_weapon_pad_obj_3", // 203,
	"obj_f_weapon_pad_obj_4", // 204,
	"obj_f_weapon_pad_obj_5", // 205,
	"obj_f_weapon_pad_ias_1", // 206,
	"obj_f_weapon_pad_i64as_1", // 207,
	"obj_f_weapon_end", // 208,
	"obj_f_ammo_begin", // 209,
	"obj_f_ammo_flags", // 210,
	"obj_f_ammo_quantity", // 211,
	"obj_f_ammo_type", // 212,
	"obj_f_ammo_pad_i_1", // 213,
	"obj_f_ammo_pad_i_2", // 214,
	"obj_f_ammo_pad_obj_1", // 215,
	"obj_f_ammo_pad_ias_1", // 216,
	"obj_f_ammo_pad_i64as_1", // 217,
	"obj_f_ammo_end", // 218,
	"obj_f_armor_begin", // 219,
	"obj_f_armor_flags", // 220,
	"obj_f_armor_ac_adj", // 221,
	"obj_f_armor_max_dex_bonus", // 222,
	"obj_f_armor_arcane_spell_failure", // 223,
	"obj_f_armor_armor_check_penalty", // 224,
	"obj_f_armor_pad_i_1", // 225,
	"obj_f_armor_pad_ias_1", // 226,
	"obj_f_armor_pad_i64as_1", // 227,
	"obj_f_armor_end", // 228,
	"obj_f_money_begin", // 229,
	"obj_f_money_flags", // 230,
	"obj_f_money_quantity", // 231,
	"obj_f_money_type", // 232,
	"obj_f_money_pad_i_1", // 233,
	"obj_f_money_pad_i_2", // 234,
	"obj_f_money_pad_i_3", // 235,
	"obj_f_money_pad_i_4", // 236,
	"obj_f_money_pad_i_5", // 237,
	"obj_f_money_pad_ias_1", // 238,
	"obj_f_money_pad_i64as_1", // 239,
	"obj_f_money_end", // 240,
	"obj_f_food_begin", // 241,
	"obj_f_food_flags", // 242,
	"obj_f_food_pad_i_1", // 243,
	"obj_f_food_pad_i_2", // 244,
	"obj_f_food_pad_ias_1", // 245,
	"obj_f_food_pad_i64as_1", // 246,
	"obj_f_food_end", // 247,
	"obj_f_scroll_begin", // 248,
	"obj_f_scroll_flags", // 249,
	"obj_f_scroll_pad_i_1", // 250,
	"obj_f_scroll_pad_i_2", // 251,
	"obj_f_scroll_pad_ias_1", // 252,
	"obj_f_scroll_pad_i64as_1", // 253,
	"obj_f_scroll_end", // 254,
	"obj_f_key_begin", // 255,
	"obj_f_key_key_id", // 256,
	"obj_f_key_pad_i_1", // 257,
	"obj_f_key_pad_i_2", // 258,
	"obj_f_key_pad_ias_1", // 259,
	"obj_f_key_pad_i64as_1", // 260,
	"obj_f_key_end", // 261,
	"obj_f_written_begin", // 262,
	"obj_f_written_flags", // 263,
	"obj_f_written_subtype", // 264,
	"obj_f_written_text_start_line", // 265,
	"obj_f_written_text_end_line", // 266,
	"obj_f_written_pad_i_1", // 267,
	"obj_f_written_pad_i_2", // 268,
	"obj_f_written_pad_ias_1", // 269,
	"obj_f_written_pad_i64as_1", // 270,
	"obj_f_written_end", // 271,
	"obj_f_bag_begin", // 272,
	"obj_f_bag_flags", // 273,
	"obj_f_bag_size", // 274,
	"obj_f_bag_end", // 275,
	"obj_f_generic_begin", // 276,
	"obj_f_generic_flags", // 277,
	"obj_f_generic_usage_bonus", // 278,
	"obj_f_generic_usage_count_remaining", // 279,
	"obj_f_generic_pad_ias_1", // 280,
	"obj_f_generic_pad_i64as_1", // 281,
	"obj_f_generic_end", // 282,
	"obj_f_critter_begin", // 283,
	"obj_f_critter_flags", // 284,
	"obj_f_critter_flags2", // 285,
	"obj_f_critter_abilities_idx", // 286,
	"obj_f_critter_level_idx", // 287,
	"obj_f_critter_race", // 288,
	"obj_f_critter_gender", // 289,
	"obj_f_critter_age", // 290,
	"obj_f_critter_height", // 291,
	"obj_f_critter_weight", // 292,
	"obj_f_critter_experience", // 293,
	"obj_f_critter_pad_i_1", // 294,
	"obj_f_critter_alignment", // 295,
	"obj_f_critter_deity", // 296,
	"obj_f_critter_domain_1", // 297,
	"obj_f_critter_domain_2", // 298,
	"obj_f_critter_alignment_choice", // 299,
	"obj_f_critter_school_specialization", // 300,
	"obj_f_critter_spells_known_idx", // 301,
	"obj_f_critter_spells_memorized_idx", // 302,
	"obj_f_critter_spells_cast_idx", // 303,
	"obj_f_critter_feat_idx", // 304,
	"obj_f_critter_feat_count_idx", // 305,
	"obj_f_critter_fleeing_from", // 306,
	"obj_f_critter_portrait", // 307,
	"obj_f_critter_money_idx", // 308,
	"obj_f_critter_inventory_num", // 309,
	"obj_f_critter_inventory_list_idx", // 310,
	"obj_f_critter_inventory_source", // 311,
	"obj_f_critter_description_unknown", // 312,
	"obj_f_critter_follower_idx", // 313,
	"obj_f_critter_teleport_dest", // 314,
	"obj_f_critter_teleport_map", // 315,
	"obj_f_critter_death_time", // 316,
	"obj_f_critter_skill_idx", // 317,
	"obj_f_critter_reach", // 318,
	"obj_f_critter_subdual_damage", // 319,
	"obj_f_critter_pad_i_4", // 320,
	"obj_f_critter_pad_i_5", // 321,
	"obj_f_critter_sequence", // 322,
	"obj_f_critter_hair_style", // 323,
	"obj_f_critter_strategy", // 324,
	"obj_f_critter_pad_i_3", // 325,
	"obj_f_critter_monster_category", // 326,
	"obj_f_critter_pad_i64_2", // 327,
	"obj_f_critter_pad_i64_3", // 328,
	"obj_f_critter_pad_i64_4", // 329,
	"obj_f_critter_pad_i64_5", // 330,
	"obj_f_critter_damage_idx", // 331,
	"obj_f_critter_attacks_idx", // 332,
	"obj_f_critter_seen_maplist", // 333,
	"obj_f_critter_pad_i64as_2", // 334,
	"obj_f_critter_pad_i64as_3", // 335,
	"obj_f_critter_pad_i64as_4", // 336,
	"obj_f_critter_pad_i64as_5", // 337,
	"obj_f_critter_end", // 338,
	"obj_f_pc_begin", // 339,
	"obj_f_pc_flags", // 340,
	"obj_f_pc_pad_ias_0", // 341,
	"obj_f_pc_pad_i64as_0", // 342,
	"obj_f_pc_player_name", // 343,
	"obj_f_pc_global_flags", // 344,
	"obj_f_pc_global_variables", // 345,
	"obj_f_pc_voice_idx", // 346,
	"obj_f_pc_roll_count", // 347,
	"obj_f_pc_pad_i_2", // 348,
	"obj_f_pc_weaponslots_idx", // 349,
	"obj_f_pc_pad_ias_2", // 350,
	"obj_f_pc_pad_i64as_1", // 351,
	"obj_f_pc_end", // 352,
	"obj_f_npc_begin", // 353,
	"obj_f_npc_flags", // 354,
	"obj_f_npc_leader", // 355,
	"obj_f_npc_ai_data", // 356,
	"obj_f_npc_combat_focus", // 357,
	"obj_f_npc_who_hit_me_last", // 358,
	"obj_f_npc_waypoints_idx", // 359,
	"obj_f_npc_waypoint_current", // 360,
	"obj_f_npc_standpoint_day_INTERNAL_DO_NOT_USE", // 361,
	"obj_f_npc_standpoint_night_INTERNAL_DO_NOT_USE", // 362,
	"obj_f_npc_faction", // 363,
	"obj_f_npc_retail_price_multiplier", // 364,
	"obj_f_npc_substitute_inventory", // 365,
	"obj_f_npc_reaction_base", // 366,
	"obj_f_npc_challenge_rating", // 367,
	"obj_f_npc_reaction_pc_idx", // 368,
	"obj_f_npc_reaction_level_idx", // 369,
	"obj_f_npc_reaction_time_idx", // 370,
	"obj_f_npc_generator_data", // 371,
	"obj_f_npc_ai_list_idx", // 372,
	"obj_f_npc_save_reflexes_bonus", // 373,
	"obj_f_npc_save_fortitude_bonus", // 374,
	"obj_f_npc_save_willpower_bonus", // 375,
	"obj_f_npc_ac_bonus", // 376,
	"obj_f_npc_add_mesh", // 377,
	"obj_f_npc_waypoint_anim", // 378,
	"obj_f_npc_pad_i_3", // 379,
	"obj_f_npc_pad_i_4", // 380,
	"obj_f_npc_pad_i_5", // 381,
	"obj_f_npc_ai_flags64", // 382,
	"obj_f_npc_pad_i64_2", // 383,
	"obj_f_npc_pad_i64_3", // 384,
	"obj_f_npc_pad_i64_4", // 385,
	"obj_f_npc_pad_i64_5", // 386,
	"obj_f_npc_hitdice_idx", // 387,
	"obj_f_npc_ai_list_type_idx", // 388,
	"obj_f_npc_pad_ias_3", // 389,
	"obj_f_npc_pad_ias_4", // 390,
	"obj_f_npc_pad_ias_5", // 391,
	"obj_f_npc_standpoints", // 392,
	"obj_f_npc_pad_i64as_2", // 393,
	"obj_f_npc_pad_i64as_3", // 394,
	"obj_f_npc_pad_i64as_4", // 395,
	"obj_f_npc_pad_i64as_5", // 396,
	"obj_f_npc_end", // 397,
	"obj_f_trap_begin", // 398,
	"obj_f_trap_flags", // 399,
	"obj_f_trap_difficulty", // 400,
	"obj_f_trap_pad_i_2", // 401,
	"obj_f_trap_pad_ias_1", // 402,
	"obj_f_trap_pad_i64as_1", // 403,
	"obj_f_trap_end", // 404,
	"obj_f_total_normal", // 405,
	"obj_f_transient_begin", // 406,
	"obj_f_render_color", // 407,
	"obj_f_render_colors", // 408,
	"obj_f_render_palette", // 409,
	"obj_f_render_scale", // 410,
	"obj_f_render_alpha", // 411,
	"obj_f_render_x", // 412,
	"obj_f_render_y", // 413,
	"obj_f_render_width", // 414,
	"obj_f_render_height", // 415,
	"obj_f_palette", // 416,
	"obj_f_color", // 417,
	"obj_f_colors", // 418,
	"obj_f_render_flags", // 419,
	"obj_f_temp_id", // 420,
	"obj_f_light_handle", // 421,
	"obj_f_overlay_light_handles", // 422,
	"obj_f_internal_flags", // 423,
	"obj_f_find_node", // 424,
	"obj_f_animation_handle", // 425,
	"obj_f_grapple_state", // 426,
	"obj_f_transient_end", // 427,
	"obj_f_type", // 428,
	"obj_f_prototype_handle" // 429
};

static const char *ObjTypeNames[] = {
	"obj_t_portal", // 0
	"obj_t_container", // 1
	"obj_t_scenery", // 2
	"obj_t_projectile", // 3
	"obj_t_weapon", // 4
	"obj_t_ammo", // 5
	"obj_t_armor", // 6
	"obj_t_money", // 7
	"obj_t_food", // 8
	"obj_t_scroll", // 9
	"obj_t_key", // 10
	"obj_t_written", // 11
	"obj_t_generic", // 12
	"obj_t_pc", // 13
	"obj_t_npc", // 14
	"obj_t_trap", // 15
	"obj_t_bag" // 16
};

static const char* unknownObject = "obj_t_unknown";

const char* GetObjectTypeName(ObjectType type) {
	if (type < std::size(ObjTypeNames)) {
		return ObjTypeNames[type];
	}
	return unknownObject;
}

const char* GetObjectFieldName(obj_f field) {
	return ObjFieldNames[field];
}
