using UnityEngine;

public class spiderAnimation : MonoBehaviour
{

    public float delayMaximo = 5.0f;

    private Animation spiderAnim;
    private bool started = false;
    private float timeStart;
    private float timeDelay;

    // Start is called before the first frame update
    void Start()
    {
        timeStart = Time.time;
        timeDelay = Random.Range(0.0f, delayMaximo);
        spiderAnim = GetComponentInChildren<Animation>();
    }

    // Update is called once per frame
    void Update()
    {
        if (!started) {
            if (Time.time > timeStart+timeDelay)
            {
                spiderAnim["SpiderUpDown"].wrapMode = WrapMode.Loop;
                spiderAnim.wrapMode = WrapMode.Loop;
                spiderAnim.Play("SpiderUpDown");
                started = true;
            }
        }
        
    }
}

