<?php

include ("stringconst.inc");

function userPwdCheck ($userName, $userPass)
{
  global $linkDB;
  
  $qCheckUsr = " SELECT *
                 FROM tbUsers
                 WHERE userName = '$userName' and userpass = '$userPass'                    
                   ";
  
  $result = mysql_query ($qCheckUsr, $linkDB);
  
  if ( ! $result )
    die (STR_ERROR_Password .mysql_error());
    
  if ( mysql_num_rows ( $result) )
    return mysql_fetch_array ( $result ); //Return user's data
   
  return 0; //return False
}

function userCheckSession ()
{
 global $session, $linkDB;
 
 $qRegistered = getTbRow ("tbUsers", "idUser", $session[idUser]);
 
 if ( ! $qRegistered
       || $qRegistered [userName] != $session [userName]
       || $qRegistered [userPass] != $session [userPass]
    ) 
  { 
    header (LOCATION_INIT);    
    exit;
  }  
 
 return $qRegistered; 
 
}

function ClearSession ($idUser, $cUserName, $cUserPassword, $nUserLevel)
{
   global $session;
   
   $session [idUser] = $idUser;
   $session [cUserName] = $cUserName;
   $session [cUserPassword] = $cUserPassword;
   $session [nUserLevel] = $nUserLevel; 
}  

?>
