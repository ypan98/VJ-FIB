using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayMusicLvl3 : MonoBehaviour
{

    void Start()
    {
        FindObjectOfType<AudioManager>().Play("musiclvl3");
    }

}