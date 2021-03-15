// setInterval(function ( ) {
//     var xhttp = new XMLHttpRequest();
//     xhttp.onreadystatechange = function() {
//       if (this.readyState == 4 && this.status == 200) {
//         document.getElementById("temperature").innerHTML = this.responseText;
//       }
//     };
//     xhttp.open("GET", "/values", true);
//     xhttp.send();
// }, 10000 ) ;
  

// const url="http://api.openweathermap.org/data/2.5/forecast?id=3179649&appid={APIKEY}";
// async function fullCall(){ 
//     let call= await fetch(url);

//     let response = await call.json();
//     console.log(response);
//     document.getElementById("weather-today").innerHTML=response.list[0].weather[0].main;
//     document.getElementById("temperature-today").innerHTML=(parseInt(response.list[0].main.feels_like)-273).toString()+"° C";
//     // document.getElementById("weather-tomorrow").innerHTML=response.list[0].weather[0].main;
//     // document.getElementById("temperature-tomorrow").innerHTML=(parseInt(response.list[0].main.feels_like)-273).toString()+"° C";
// }

// fullCall();



//SHOW/HIDE INFO TEXT---------
let btn_info1=document.getElementById("dd1");
let btn_info2=document.getElementById("dd2");
let btn_info3=document.getElementById("dd3");
let a=true;
let b=true;
let c=true;
btn_info1.addEventListener("click",()=>{
  let item=document.getElementById("info1");
  a ? item.style.display="inline" : item.style.display="none"; 
  a=!a; 
});
btn_info2.addEventListener("click",()=>{
  let item=document.getElementById("info2");
  b ? item.style.display="inline" : item.style.display="none";   
  b=!b; 
});
btn_info3.addEventListener("click",()=>{
  let item=document.getElementById("info3");
  c ? item.style.display="inline" : item.style.display="none"; 
  c=!c; 
});
