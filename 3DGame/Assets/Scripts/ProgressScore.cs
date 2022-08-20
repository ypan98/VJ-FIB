using UnityEngine;
using UnityEngine.UI;

public class ProgressScore : MonoBehaviour
{
    public static ProgressScore instance;
    public float end;

    private GameObject player;
    private float start;
    private Text text;
    public float progress = 0.0f;

    void Start()
    {
        instance = this;
        player = GameObject.Find("Player");
        start = player.transform.position.z;
        text = GetComponent<Text>();
    }


    void Update()
    {
        if (playerMovement.instance.dead != true) { 
            progress = (player.transform.position.z / (end - start)) * 100;
            if (progress <= 100.0f) text.text = progress.ToString("0") + "%";
        }
    }
}
