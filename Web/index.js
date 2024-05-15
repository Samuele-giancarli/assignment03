function updateChart() {
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
);


function createHttpObject() {
  try {return new XMLHttpRequest();}
  catch (error) {}

  throw new Error("Could not create HTTP request object.");
}

var request = new createHttpObject();
request.open("GET", "http://localhost/Assignement-03/assignment03/Web", true);
request.send(null);
console.log(request.responseText);


updateChart();
