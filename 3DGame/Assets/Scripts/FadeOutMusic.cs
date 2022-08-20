using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FadeOutMusic : MonoBehaviour
{

    public string musicName;
    public float volume = 0;

    void Update()
    {
        AudioManager.instance.AjustIntensitySound(musicName, volume);
    }
}
