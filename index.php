<?php

// insert your MySQL login information here
$username=""; 
$password="";
$database="";

$direction = $_GET["direction"];

if ($direction != "") {
  mysql_connect("localhost",$username,$password);
  @mysql_select_db($database) or die( "Unable to select database");
  $query = "UPDATE ai_robotics SET direction = '$direction' WHERE ref = 0";
  mysql_query($query);
  mysql_close();
}


?>


<html>

  <head>
    <meta http-equiv="Content-Type" content="text/html; charset=windows-1252">
    <meta name="viewport" content="width=device-width, initial-scale=1.0, maximum-scale=1.0, user-scalable=no" />
  </head>

  <body>

    <table align="center">
    <div text-align="right">
      <tr align="center">
        <td align="center"><a href="index.php?direction=a"><img src="up_arrow.jpg" border="0"></a></td>
      </tr>

      <tr align="center">
        <td align="center">
          <a href="index.php?direction=d"><img src="left_arrow.jpg" border="0"></a>
          <a href="index.php?direction=g"><img src="stop_icon.jpg" border="0"></a>
          <a href="index.php?direction=b"><img src="right_arrow.jpg" border="0"></a>
        </td>
      </tr>

      <tr>
        <td align="center"><a href="index.php?direction=c"><img src="down_arrow.jpg" border="0"></a></td>
      </tr>
    </div>
    </table>

  </body>

</html>
