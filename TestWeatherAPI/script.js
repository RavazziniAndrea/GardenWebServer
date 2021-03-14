const url="http://api.openweathermap.org/data/2.5/forecast?id=3179649&appid={API_KEY}";

async function fullCall(){ 
    let call= await fetch(url);

    let response = await call.json();
    console.log(response.list[0]);
}

fullCall();
