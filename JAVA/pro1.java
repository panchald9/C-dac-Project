import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.Statement;
import java.sql.ResultSet;

/**
 * pro1
 */
public class pro1 {

    public static void main(String[] args) {
        String url = "jdbc:mysql://localhost:3310/kuchbhi";
        String User = "root";
        String Password = "1234";

        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // Load the JDBC driver (optional for JDBC 4.0+)
            Class.forName("com.mysql.cj.jdbc.Driver");

            // Establish the connection
            connection = DriverManager.getConnection(url, User, Password);

            // Create a statement
            statement = connection.createStatement();

            // Execute a query
            String sql = "SELECT name, password FROM cust";
            resultSet = statement.executeQuery(sql);

            // Process the results
            while (resultSet.next()) {
                String name = resultSet.getString("name");
                String pss = resultSet.getString("password");

                // Display the results
                System.out.println("Name: " + name + ", Password: " + pss);
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // Close the resources
            try {
                if (resultSet != null) resultSet.close();
                if (statement != null) statement.close();
                if (connection != null) connection.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}
