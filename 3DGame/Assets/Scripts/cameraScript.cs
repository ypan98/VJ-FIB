using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class cameraScript : MonoBehaviour
{
    public Vector3 offset = new Vector3(0, 0, -5);
    public float yFixed = 3.8921f;
    public float xFixed = -5.5f;

    // Start is called before the first frame update
    void Start()
    {
       
    }

    // Update is called once per frame
    void Update()
    {
        Vector3 playerPos = GameObject.Find("Player").transform.position;
        playerPos.y = yFixed;
        playerPos.x = xFixed;
        transform.position = playerPos + offset;
    }
}
