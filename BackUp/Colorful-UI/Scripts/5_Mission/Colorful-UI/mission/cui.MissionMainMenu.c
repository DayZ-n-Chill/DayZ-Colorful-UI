modded class MissionMainMenu
{
	private ref AbstractWave m_MenuMusic;
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        PlayMusic();
    }
    
    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        StopMusic();
    }
	
	override void PlayMusic()
	{
		if ( !m_MenuMusic )
		{
			ref SoundParams soundParams	= new SoundParams("Main_Music_Menu_SoundSet");
			ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
			ref SoundObject soundObject	= soundBuilder.BuildSoundObject();
			
			soundObject.SetKind( WaveKind.WAVEMUSIC );
			m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
			m_MenuMusic.Loop( true );
			m_MenuMusic.Play();
		}
	}
}
