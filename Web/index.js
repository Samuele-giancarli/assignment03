function updateChart() {
  async function fetchData() {
    const url = 'http://localhost/assignament-03-web/waterLevel.json';
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

updateChart();