[EntityEditorProps(category: "GameScripted/GPS", description: "GPS ")]
class SCR_GpsClass : ScriptComponentClass
{
    // prefab properties here
}

class SCR_Gps : ScriptComponent
{
	// If the map is open or not
	protected bool m_bIsMapOpen;
	protected bool m_bIsFirstTimeOpened = true;
	
	// Map Instance
	protected SCR_MapEntity m_MapEntity = null;
	
	// When the script initializes
	override void EOnInit(IEntity owner)
	{
		Print("SCR_Gps: Script initializing");
		
		// If the map is null, get the instance
		if (!m_MapEntity) {
			Print("SCR_Gps: Getting Map Instance");
			m_MapEntity = SCR_MapEntity.GetMapInstance();
		}
			
		Print("SCR_Gps: Adding OnMapOpen/Close Handlers");
		SCR_MapEntity.GetOnMapOpen().Insert(OnMapOpen);
		SCR_MapEntity.GetOnMapClose().Insert(OnMapClose);
		
		Print("SCR_Gps: Script initialized");
	}
	
	protected void OnMapOpen(MapConfiguration config)
	{
		Print("SCR_Gps: The map was opened");
	}
	
	protected void OnMapClose(MapConfiguration config)
	{
		Print("SCR_Gps: The map was closed");
	}
}