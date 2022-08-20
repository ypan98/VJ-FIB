using UnityEngine;
using UnityEngine.UI;
using UnityEngine.SceneManagement;

public class ManageGame : MonoBehaviour
{
    public GameObject gameOver;
    public GameObject levelCompleted;
    public Button OverRestartButton;
    public Button OverMenuButton;
    public Button CompletedMenuButton;

    void Start()
    {
        OverRestartButton.onClick.AddListener(RestartLevel);
        OverMenuButton.onClick.AddListener(BackToMenu);
        CompletedMenuButton.onClick.AddListener(BackToMenu);
    }

    void Update()
    {
        if (playerMovement.instance.dead == true)
        {
            gameOver.SetActive(true);
        }
        if (ProgressScore.instance.progress >= 100.0f)
        {
            levelCompleted.SetActive(true);
        }
    }

    public void RestartLevel()
    {
        AudioManager.instance.StopAllSounds();
        Application.LoadLevel(Application.loadedLevel);
    }

    public void BackToMenu()
    {
        AudioManager.instance.StopAllSounds();
        Application.LoadLevel(0);
    }

}
