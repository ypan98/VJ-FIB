using UnityEngine;

public class SpawnParticles : MonoBehaviour
{

    public GameObject player;
    public GameObject AnimPrefab;
    public float spawnDistance = 12;
    public Vector3 spawnPoint;
    public string soundName;

    private float objectZ;
    private bool spawned = false;

    void Start()
    {
        objectZ = GetComponent<Transform>().position.z;
    }

    void Update()
    {
        if (!spawned && player.transform.position.z >= objectZ - spawnDistance)
        {
            Instantiate(AnimPrefab, spawnPoint, Quaternion.identity);
            if (soundName != null) {
                FindObjectOfType<AudioManager>().Play(soundName);
            }

            spawned = true;

        }
    }
}
