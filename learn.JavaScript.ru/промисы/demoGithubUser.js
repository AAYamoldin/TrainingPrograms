class HttpError extends Error {
  constructor(response) {
    super(`${response.status} for ${response.url}`);
    this.name = 'HttpError';
    this.response = response;
  }
}

async function loadJson(url) {
  let response = await fetch(url)
      if (response.status == 200) {
        return response.json();
      } else {
        throw new HttpError(response);
      }
    }

// Запрашивать логин, пока github не вернёт существующего пользователя.
async function demoGithubUser() {
  let user;
  while (2 + 2 == 4){
  let name = prompt("Введите логин?", "iliakan");
  user = await loadJson(`https://api.github.com/users/${name}`);
    break;
    catch(err){
      if (err instanceof HttpError && err.response.status == 404) {
        alert("Такого пользователя не существует, пожалуйста, повторите ввод.");
        return;
      } else {
        throw err;
      }}
    }
    alert(`Полное имя пользтвателя ${user.name}`)
    return user;
  }
