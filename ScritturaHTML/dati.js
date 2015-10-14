function inserisciRuolo(ruolo, nomi){
document.write("<option value=\""+nomi+"\">"+ruolo+"</option>")
}
function cambiaRuolo(){
var e = document.getElementById("listaRuoli").value
var lista=e.split("\n")
document.getElementById("demo").innerHTML = "<textarea readonly rows=\""+(lista.length+1)+"\" cols=\"30\">" + e + "</textarea>"
}

var ruolo1="studente"
var nomi1="Ciro\nVescera"

var ruolo2="professore"
var nomi2="Trotta\nTesti"

var ruolo3="personaleATA"
var nomi3="Bidello messicano\nGiardiniere Willy"

var ruolo4="preside"
var nomi4="Rita"
