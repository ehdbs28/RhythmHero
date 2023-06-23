#include "SceneManager.h"
#include "Scene.h"

void SceneManager::RegisterScene(const wstring& sceneName, shared_ptr<Scene> scene)
{
	if (sceneName.empty() || scene == NULL)
		return;

	m_sceneContainer.insert({ sceneName, scene });
}

void SceneManager::LoadScene(const wstring& sceneName)
{
	if (m_activeScene != NULL) {
		m_activeScene->Release();
		m_activeScene = NULL;
	}

	auto iter = m_sceneContainer.find(sceneName);
	if (iter != m_sceneContainer.end()) {
		m_activeScene = iter->second;
		m_activeScene->Init();
	}
}

void SceneManager::Init()
{
	m_activeScene = NULL;
}

void SceneManager::Update(float dt)
{
	if (m_activeScene == NULL)
		return;

	m_activeScene->Update(dt);
}

void SceneManager::Render()
{
	if (m_activeScene == NULL)
		return;
	
	m_activeScene->Render();
}

void SceneManager::Release()
{
	m_activeScene = NULL;
}
