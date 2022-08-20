using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimEagle : MonoBehaviour
{

    public float distance;
    public GameObject player;
    public bool inv;

    private float posZ;
    private Animation anim;
    private bool started = false;

    void Start()
    {
        posZ = GetComponent<Transform>().position.z;
        anim = GetComponent<Animation>();
    }

    // Update is called once per frame
    void Update()
    {
        if (!started)
        {
            if (player.transform.position.z >= posZ - distance)
            {
                if (!inv) anim.Play("EagleFly");
                else anim.Play("EagleFlyInv");
                GetComponent<AudioSource>().Play();
                //FindObjectOfType<AudioManager>().Play("columnimpact");
                started = true;
            }
        }
    }
}
