<?php
	include ("dbconnection.inc");
  include ("users.inc");

  $msg= "";
  
  if (isset ($actionflag) && $actionflag = "login")
  {
    
    if (empty ($form[cUserName]) || empty ($form[cUserPassword]))
      $msg .= STR_ERROR_FIELDREQUIRED; 
    if ( ! ($row_array = chequeoClave ($form[cUserName], $form[cUserPassword]) ) )
      $msg .= STR_ERROR_INVALIDPASS;         
  
    if (($msg == "")) //It's all rigth
    { 
      ClearSession ($row_array [idUser], $row_array [userName], $row_array [userpass], $row_array [userlevel] );
      header (LOCATION_INTOINIT);  
    }        
  } 

?>

<html>
  <head>
  <meta http-equiv="content-type" content="text/html; charset=windows-1250">
  <meta name="generator" content="Magoo with VI">
  <title> Ingreso de Usuarios </title>
  </head>
  <body>   
   <?php     
       if ($msg != "")
       {
         print "<p><b>$msg</b></p>";
       }
      $msg = "";
   ?>

      
  <form action = "doctrlogin.php">
    <p>  
       <input type="hidden" name="actionflag" value="login">
       <input type="hidden" name="<?php print session_name() ?>" value= "<?php print session_id() ?>">
    </p>   
    <p>
       Usuario: <br>
       <input type= "text" name="form[cUserName]" value="<?php print $form[cUserName] ?>" maxlength = 50>
    </p>
    <p>
       Clave: <br>
       <input type= "password" name= "form[cUserPassword]" value = "<?php print $form[cUserPassword] ?>" maxlength = 30>
    </p>
    <p>
      <input type= "submit" value="Ingresar">
    </p>
  </form>

  </body>
</html>

