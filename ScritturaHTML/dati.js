function inserisciRuolo(ruolo, nomi){
document.write("<option value=\""+nomi+"\">"+ruolo+"</option>")
}
function cambiaRuolo(){
var e = document.getElementById("listaRuoli").value
var lista=e.split("\n")
document.getElementById("demo").innerHTML = "<textarea readonly rows=\""+(lista.length+1)+"\" cols=\"30\">" + e + "</textarea>"
if (mostra==false){
document.getElementById("demo").style.display = "none";
}
}
var mostra=true
function cambio(){
if(document.getElementById("listaRuoli").selectedIndex!=0){
if (mostra==true){
document.getElementById("demo").style.display = "none";
document.getElementById("bottone").textContent="Mostra Nomi";
mostra=false
}
else{
document.getElementById("demo").style.display = "block";
document.getElementById("bottone").textContent = "Nascondi nomi";
mostra=true
}
}
}


var ruolo1="studente"
var nomi1="Ciro\nVescera"

var ruolo2="professore"
var nomi2="Trotta\nTesti"

var ruolo3="personaleATA"
var nomi3="Bidello messicano\nGiardiniere Willy"

var ruolo4="preside"
var nomi4="Rita"
