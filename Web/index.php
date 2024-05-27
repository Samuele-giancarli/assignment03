<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Prova http</title>
</head>
<body>
    <script>
        fetch("http://localhost:8080/")
        .then((response) => response.json())
        .then((json) => console.log(json));

    </script>

    <!--
        About the River Monitoring Dashboard
        The dashboard has two main responsibilities:
        To visualise the state of the River Monitoring system. In particular:
        - The graph of water level trend, considering a certain temporal window (the last N minutes)
        - The state of the system (NORMAL, ALARM-TOO-LOW, PRE-ALARM-TOO-HIGH, ALARM-TOO-HIGH, ALARM-TOO-HIGH-CRITIC)
        - The valve opening level
        - To allow a user for controlling manually, from remote, the valve opening level
    -->
    <h1>River Monitoring Dashboard</h1>
    <div class="functionality container">
        <div style="width: 800px;">
            <canvas id="acquisitions"></canvas>
        </div>

        <div>
            <p>State:<p>
            <p><!--Determinato con js--></p>
        </div>

        <div>
            <p>Valve's opening angle:</p>
            <p><!--Determinato con js--></p>
        </div>

        <div>
            <p>Manual Control:</p>
            <button class="clickbutton"><!--Per passare da manuale a automatico e contrario--></button>
            <div>
                <p>Closed</p>
                <input type="range" min="1" max="100" value="50" class="slider" id="myRange">
                <p>Open</p>
            </div>
        </div>
    </div>
    
    <!--<script type="module" src="index.js"></script>-->

    <!--<script src="https://cdn.jsdelivr.net/npm/chart.js"></script>-->


</body>
</html>