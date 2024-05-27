const button = document.querySelector(".clickbutton");

/*function updateChart() {
  async function fetchData() {
    const url = 'http://localhost/Assignement-03/assignment03/Web/waterLevel.json';
    const response = await fetch(url);
    const datapoints = await response.json();
    return datapoints;
  }

  fetchData().then(datapoints => {
    const level = datapoints.WaterLevel.map(
      function(index){
        return index.level;
      });

    const timestamp = datapoints.WaterLevel.map(
      function(index){
        return index.timeStamp;
      });

    // Update the data object in the config object
    config.data = {
      labels: timestamp,
      datasets: [{
        label: 'Water Level',
        data: level,
        backgroundColor: 'rgba(75, 192, 192, 0.2)',
        borderColor: 'rgba(75, 192, 192, 1)',
        borderWidth: 1
      }]
    };

    myChart.update();
  });
}

const config = {
  type: 'bar',
  data: {
    labels: [],
    datasets: []
  },
  options: {
    scales: {
      y: {
        beginAtZero: true
      }
    }
  }
};

const myChart = new Chart(
  document.getElementById('acquisitions'),
  config
);*/

window.onload(() => {
  var io = require('socket.io-client')
  var socket = io.connect('http://localhost:8080');

  socket.on('connect', function () {

      console.log('Connected!\n\tSending query ...');

      socket.emit('myEvent', '\tI am the query', function (data) {
        console.log(data); 
      });

  });
})

/*
const getData = () =>{
  console.log("Funzioneaperta");
  fetch('http://localhost/Assignement-03/assignment03/Web', {
    method: "POST",
    headers: {
      'Content-Type': 'application/json',
      'Accept': 'application/json'
    }
  })
  .then(response => {
    if (!response.ok) {
      throw new Error(`HTTP error! status: ${response.status}`);
    }
    console.log(response);
    return response.json();
  })
  .then(data => console.log(data))
  .catch(error => console.error('Error:', error));
}

button.addEventListener('click', () => {
  console.log("Grazie per avermi cliccato");
  getData();
})
*/