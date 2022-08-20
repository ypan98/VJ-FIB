using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimSlime : MonoBehaviour
{

    public float distance;
    private float widthDistance = 1.5f;
    private GameObject player;
    private float posZ;
    private float posX;
    private Animation anim;
    private bool started = false;

    void Start()
    {
        posZ = GetComponent<Transform>().position.z;
        posX = GetComponent<Transform>().position.x;
        anim = GetComponent<Animation>();
        player = GameObject.Find("Player");
    }

    void Update()
    {
        if (!started)
        {
            if (player.transform.position.z >= posZ - distance && player.transform.position.z < posZ)
            {
                if (player.transform.position.x > posX - widthDistance && player.transform.position.x < posX + widthDistance)
                { 
                    anim.Play("SlimeJump");
                    int num = Random.Range(1, 4);
                    if (num == 1) FindObjectOfType<AudioManager>().Play("slime1");
                    else if (num == 2) FindObjectOfType<AudioManager>().Play("slime2");
                    else if (num == 3) FindObjectOfType<AudioManager>().Play("slime3");
                    started = true;
                }
            }
        }
    }
}