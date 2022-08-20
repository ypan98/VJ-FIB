using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BridgeScript : MonoBehaviour
{

    public float startZ;
    public float endZ;

    private GameObject p;
    private float middleX;
    private float rangeX = 20.0f;

    void Start()
    {
        p = GameObject.Find("Player");
        middleX = gameObject.transform.position.x;
    }

    void Update()
    {
        if (p.transform.position.z >= startZ && p.transform.position.z < endZ)
        {
            if (p.transform.position.x > middleX - rangeX && p.transform.position.x < middleX + rangeX) 
            {
                Vector3 v = new Vector3(-5.5f,1.0f,345.5f);
                gameObject.transform.position = new Vector3(middleX, 1.0f, p.transform.position.z); ;
            }
        }
    }
}
