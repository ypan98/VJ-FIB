using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Play3DMusic : MonoBehaviour
{
    public float distance;

    private GameObject player;
    private float posZ;
    private bool started = false;

    void Start()
    {
        posZ = GetComponent<Transform>().position.z;
        player = GameObject.Find("Player");
    }

    // Update is called once per frame
    void Update()
    {
        if (!started)
        {
            if (player.transform.position.z >= posZ - distance)
            {
                GetComponent<AudioSource>().Play();
                started = true;
                Debug.Log("Playing noise");
            }
        }
    }
}

