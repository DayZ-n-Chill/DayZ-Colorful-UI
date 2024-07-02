modded class DynamicMusicPlayerRegistry
{
    protected override void RegisterTracksMenu()
	{
		m_TracksMenu = new array<ref DynamicMusicTrackData>();
		RegisterTrackMenu("Music_Menu_SoundSet");
	}
}
