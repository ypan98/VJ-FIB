using UnityEngine;

public class LightFollowPlayer : MonoBehaviour
{

    public Vector3 offset = new Vector3(0, 0, 0);

    // Update is called once per frame
    void Update()
    {
        Vector3 playerPos = GameObject.Find("Player").transform.position;
        transform.position = playerPos + offset;
    }
}
