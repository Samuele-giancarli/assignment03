
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

const getData = () =>{
  console.log("Funzioneaperta");
  fetch('http://localhost:8000/Assignement-03/assignment03/Web/app?level=2003', {
    method: "GET"
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
