using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimColumna : MonoBehaviour
{

    public float distance;
    public GameObject player;

    private float posZ;
    private Animation anim;
    private bool started = false;

    void Start()
    {
        posZ = GetComponent<Transform>().position.z;
        anim = GetComponent<Animation>();
    }

    void Update()
    {
        if (!started)
        {
            if (player.transform.position.z >= posZ - distance)
            {
                anim.Play("ColumnaQueCae");
                GetComponent<AudioSource>().Play();
                //FindObjectOfType<AudioManager>().Play("columnimpact");
                started = true;
            }
        }
    }
}
