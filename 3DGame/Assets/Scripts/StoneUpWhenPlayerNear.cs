using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StoneUpWhenPlayerNear : MonoBehaviour
{
    public float activationDistance = 5;
    private GameObject player;
    private Animation animation;
    private bool played;
    // Start is called before the first frame update
    void Start()
    {
        played = false;
        player = GameObject.Find("Player");
        animation = gameObject.GetComponent<Animation>();
}

    // Update is called once per frame
    void Update()
    {
        if (!played && gameObject.transform.position.z - player.transform.position.z <= activationDistance)
        {
            animation["StoneUp"].wrapMode = WrapMode.Once;
            animation.Play("StoneUp");
            played = true;
        }
    }
}
