modded class DynamicMusicPlayerRegistry
{
    protected override void RegisterTracksMenu()
	{
		m_TracksMenu = new array<ref DynamicMusicTrackData>();
		RegisterTrackMenu("DZNC_Music_Menu_SoundShader");
	}
}
