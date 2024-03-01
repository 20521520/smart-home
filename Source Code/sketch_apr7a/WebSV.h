const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
    <link rel="stylesheet" href="main.css">
    <link rel="stylesheet" href="main.js">
</head>
<body>
    <div class="head">
        <h1 class="header">SMART HOME</h1>
    </div>
    <div class="body">
        <div class="gr-sensor">
            <div class="sensor" > 
                <ion-icon id="icon-1" name="thermometer-outline"></ion-icon>    
               <h3> Nhiệt Độ</h3> 
                <span class="spansensor" id="Nhietdo">
                    0
                </span>
                C<br>
            </div>
            <div class="sensor"> 
                <ion-icon id="icon-2" name="water-outline"></ion-icon>
                <h3>Độ Ẩm</h3>
                <span class="spansensor" id="Doam">
                    0
                </span>%<br>
            </div>  
        </div>

        <div class="gr-sensor">
            <div class="sensor"> 
                <ion-icon id="icon-3" name="sunny-outline"></ion-icon>
                <h3>Ánh Sáng</h3>
                <span class="spansensor" id="Anhsang">
                    0
                </span>
                lx<br>
            </div>
            <div class="sensor"> 
                <ion-icon id="icon-4" name="cloud-download-outline"></ion-icon>
                <h3>Độ Ẩm Đất</h3> 
                <span class="spansensor" id="Doamdat">
                    0
                </span>%<br>
            </div>
        </div>
            <div class="light">
                <ion-icon id="icon-5" name="flashlight-outline"></ion-icon>
                <h3>Đèn Led</h3><button id = "denled" onclick="statusled1()"> OFF </button></div>
        </div>
 
      <script type="module" src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.esm.js"></script>
      <script nomodule src="https://unpkg.com/ionicons@7.1.0/dist/ionicons/ionicons.js"></script>
</body>

<style>
*
{
    margin: 0;
    
}
body
{
    background-color:#fff;
}
.header
{   
    height: 60px;
    background-color: #47ea47;
    display: flex;
    align-items: center;
    justify-content: center;
    font-size: 40px;
    font-family:Arial, Helvetica, sans-serif;
}

.body
{   
    display: inline;
    justify-content: center;
    align-items: center;
    
}
.gr-sensor
{   
    margin-left: 460px;
    width: 600px;
    height: 200px;
    display: flex;
    justify-content:space-evenly;
    margin-top: 30px;
    background-color:#47ea47;
    border-radius: 20px;
    align-items: center;
}

.light
{
    margin-left: 460px;
    width: 600px;
    height: 200px;
    display: flex;
    align-items:center;
    justify-content: center;
    margin-top: 30px;
    background-color:#47ea47;
    border-radius: 20px;
    
}

ion-icon {
    font-size: 50px;
  }

#icon-1
{
    color: red;
}

#icon-2
{
    color:blue;
}

#icon-3
{
    color: #fff;
}

#icon-4
{
    color: brown;
}

#icon-5
{
    color: yellow;
    margin-right: 30px;
}

#denled {
    margin-left: 30px;
    height: 50px;
    width: 70px;
    border-radius: 10px;
}

</style>

<script>

setInterval (function()
{
    getnhietdo();
    getdoam();
    getanhsang();
    getdoamdat();
}, 1000);

var i=0;
function statusled1()
{
    i = i+1;
    if (i%2 == 1)
    {
        ledon1();
    }
    if(i%2 ==0)
    {
        ledoff1();
    }
}


function getnhietdo()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==  4 && this.status==200)
        {
           document.getElementById("Nhietdo").innerHTML = this.responseText;

        }
    };
    xhttp.open("GET", "docnhietdo", true);
    xhttp.send();
}

function getdoam()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==4 && this.status==200)
        {
           document.getElementById("Doam").innerHTML = this.responseText;

        }
    };
    xhttp.open("GET","docdoam", true);
    xhttp.send();
}

function getanhsang()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==4 && this.status==200)
        {
           document.getElementById("Anhsang").innerHTML = this.responseText;

        }
    };
    xhttp.open("GET","docanhsang",true);
    xhttp.send();
}

function getdoamdat()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==4 && this.status==200)
        {
           document.getElementById("Doamdat").innerHTML = this.responseText;

        }
    };
    xhttp.open("GET", "docdoamdat", true);
    xhttp.send();
}
function ledon1()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==4 && this.status==200)
        {
           document.getElementById("denled").innerHTML = this.responseText;

        }
    };
    xhttp.open("GET","led1on",true);
    xhttp.send();
}


function ledoff1()
{
    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function()
    {
        if(this.readyState ==4 && this.status==200)
        {
           document.getElementById("denled").innerHTML = this.responseText;
        }
    };
    xhttp.open("GET","led1off",true);
    xhttp.send();
}

</script>
</html>
)=====";