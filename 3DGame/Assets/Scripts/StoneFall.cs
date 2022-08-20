using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class StoneFall : MonoBehaviour
{
    public float activationDistance = 12;
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
            animation["StoneFall"].wrapMode = WrapMode.Once;
            animation.Play("StoneFall");
            played = true;
            // Play Some Sound or Add effect
        }
    }
}
