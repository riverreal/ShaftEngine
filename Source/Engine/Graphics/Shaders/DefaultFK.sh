//Default feature keys
//Describes what inputs and what features to use
//Feature keys are usually generated

#define MAX_NUM_POINT_LIGHTS 4

//FEATURE defines
#define LIGHTING_ON 0
#define LIGHT_PBR 0

//USE defines
#define USE_V_COLOR 0
#define USE_COLOR 1
#define USE_ALBEDO 0
#define USE_NORMAL 0
#define USE_METALLIC 0
#define USE_ROUGHNESS 0

#define ALBEDO_REG_NUM (USE_ALBEDO)
#define NORMAL_REG_NUM (ALBEDO_REG_NUM + USE_NORMAL)
#define METALLIC_REG_NUM (NORMAL_REG_NUM + USE_METALLIC)
#define ROUGHNESS_REG_NUM (METALLIC_REG_NUM + USE_ROUGHNESS)