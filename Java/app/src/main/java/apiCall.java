/*
 * Ho bisogno di 
 * 1. creare uno script che generi un numero a caso fra 1 e 25 e rilevi il timestamp. Salvi tutto sul json
 * 2. creare una connessione http e mandare avanti e indietro il valore della valvola e manual/authomatic
 */

import java.util.Date;
import java.util.Random;
import java.io.IOException;
import java.net.HttpURLConnection;
import java.net.MalformedURLException;
import java.net.ProtocolException;
import java.net.URISyntaxException;
import java.net.URL;
import java.text.SimpleDateFormat;
import java.util.concurrent.TimeUnit;
import java.io.DataOutputStream;
import java.io.BufferedReader;
import java.io.InputStreamReader;




public class apiCall {
    public static void main(String[] args)
        throws URISyntaxException, IOException
    {   
        while(true) {
        Random rand = new Random();
        int randomLevel = rand.nextInt(50);

        Date date = new Date();
        SimpleDateFormat sdf = new SimpleDateFormat("MM/dd/yyyy h:mm:ss a");
        String formattedDate = sdf.format(date);

        String data = "{\"level\": " + randomLevel + ", \"timestamp\": \"" + formattedDate + "\"}";

        System.out.println("You are sending this: " + data);

        try {
            URL url = new URL("http://localhost/Assignement-03/assignment03/Web/data.php");
            HttpURLConnection connection = (HttpURLConnection) url.openConnection();
            connection.setRequestMethod("POST");
            connection.setRequestProperty("Content-Type", "application/json");
            connection.setDoOutput(true);
            DataOutputStream wr = new DataOutputStream(connection.getOutputStream());
            wr.writeBytes(data);
            wr.flush();
            wr.close();

            int responseCode = connection.getResponseCode();
            System.out.println("Response Code : " + responseCode);

            BufferedReader in = new BufferedReader(new InputStreamReader(connection.getInputStream()));
            String inputLine;
            StringBuffer response = new StringBuffer();

            while ((inputLine = in.readLine()) != null) {
                response.append(inputLine);
            }
            in.close();

            System.out.println(response.toString());
        } catch (MalformedURLException e) {
            e.printStackTrace();
        } catch (ProtocolException e) {
            e.printStackTrace();
        }
        try {
            TimeUnit.SECONDS.sleep(2);
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        }
    }
}

