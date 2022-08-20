using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerMovement : MonoBehaviour
{

    public static playerMovement instance;

    public float forwardForce = 2600;
    public float sideVelocity = 3.5f;
    public float maxVelocity = 7;
    public bool dead = false;

    Rigidbody rb;
    bool jumping = false;
    float timeBetweenMovements = 0.5f;
    float lastMovementTime = 0;


    // Start is called before the first frame update
    void Start()
    {
        instance = this;
        rb = gameObject.GetComponent<Rigidbody>();
    }


    void Update() {
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
                lastMovementTime = Time.time;
                vel.x = -sideVelocity;
                rb.velocity = vel;
                //Debug.Log(rb.velocity);
            }
            else if (Input.GetKey(KeyCode.D) || Input.GetKey("right"))
            {
                //rb.AddForce(sideForce * Time.deltaTime, 0, 0, ForceMode.VelocityChange);
                lastMovementTime = Time.time;
                vel.x = sideVelocity;
                rb.velocity = vel;
            }
        }
    }
    void FixedUpdate()
    {
        if (!dead) { 
        
            rb.AddForce(0, 0, forwardForce * Time.deltaTime);

        }
        
    }
}
