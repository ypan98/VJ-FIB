using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayMusicLvl1 : MonoBehaviour
{
    void Start()
    {
        FindObjectOfType<AudioManager>().Play("musiclvl1");
    }

}
