using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class TornadoJump : MonoBehaviour
{

    public int jumpForce = 1200;
    public GameObject player;

    private bool jumped = false;
    private float x;
    private float z;
    Rigidbody rbPlayer;

    void Start()
    {
        x = gameObject.transform.position.x;
        z = gameObject.transform.position.z;
        rbPlayer = player.GetComponent<Rigidbody>();
    }

    void Update()
    {
        if (!jumped) { 
            if (player.transform.position.z >= z && player.transform.position.z < z + 0.5f) {
                if (player.transform.position.x > x - 0.8f && player.transform.position.x < x + 0.8f) {
                    rbPlayer.AddForce(0, jumpForce, 0);
                    jumped = true;
                }
            }
        }
    }
}
