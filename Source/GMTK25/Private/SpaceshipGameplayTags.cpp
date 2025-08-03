// GMTK Game Jam 2025


#include "SpaceshipGameplayTags.h"

namespace SpaceshipGameplayTags
{
	/*Input Tags*/
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Throttle, "InputTag.Throttle");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Turn, "InputTag.Turn");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Strafe, "InputTag.Strafe");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Roll, "InputTag.Roll");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Use_Right_Tool, "InputTag.Use.Right.Tool");

	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Right_Tool, "InputTag.Equip.Right.Tool");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip_Right_Tool, "InputTag.Unequip.Right.Tool");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Equip_Left_Tool, "InputTag.Equip.Left.Tool");
	UE_DEFINE_GAMEPLAY_TAG(InputTag_Unequip_Left_Tool, "InputTag.Unequip.Left.Tool");

	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Equip_Tool, "Player.Ability.Equip.Drill");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Unequip_Tool, "Player.Ability.Unequip.Drill");
	UE_DEFINE_GAMEPLAY_TAG(Player_Ability_Use_Tool_Drill, "Player.Ability.Use.Tool.Drill");

	UE_DEFINE_GAMEPLAY_TAG(Player_Tool_Drill, "Player.Tool.Drill");

	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Equip_Tool, "Player.Event.Equip.Tool");
	UE_DEFINE_GAMEPLAY_TAG(Player_Event_Unequip_Tool, "Player.Event.Unequip.Tool");
	
}
