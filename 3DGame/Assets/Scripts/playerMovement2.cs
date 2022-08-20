using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerMovement2 : MonoBehaviour
{

    public static playerMovement2 instance;

    private float forwardForce = 2600;
    private float sideForce = 800;

    public float sideVelocity = 3.5f;
    public float maxVelocity = 5;
    public bool dead = false;

    private float zOfSnowyArea = 216;
    private float zWin = 430;
    Rigidbody rb;


    // Start is called before the first frame update
    void Start()
    {
        instance = this;
        rb = gameObject.GetComponent<Rigidbody>();
    }


    void Update()
    {
        if (!dead)
        {
            Vector3 vel = rb.velocity;
            if (vel.z > maxVelocity)
            {
                vel.z = maxVelocity;
                rb.velocity = vel;
            }

            if (Input.GetKey(KeyCode.A) || Input.GetKey("left"))
            {
                //rb.AddForce(-sideForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
                vel.x = -sideVelocity;
                rb.velocity = vel;
                //Debug.Log(rb.velocity);
            }
            else if (Input.GetKey(KeyCode.D) || Input.GetKey("right"))
            {
                //rb.AddForce(sideForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
                vel.x = sideVelocity;
                rb.velocity = vel;
            }
        }
    }
    void FixedUpdate()
    {
        bool inSnowyArea = transform.position.z >= zOfSnowyArea;
        if (!dead)
        {
            if (inSnowyArea) {
                float rF = Random.Range(0.75f, 1.15f);
                float rS = Random.Range(-1.0f, 1.0f);
                rb.AddForce(sideForce * Time.deltaTime * rS, 0, forwardForce * Time.deltaTime * rF);

            }
            else
            {
                rb.AddForce(0, 0, forwardForce * Time.deltaTime);
            }
            

        }

    }
}
