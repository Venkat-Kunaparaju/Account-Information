# Account Information
 Funcationality
    User Information
        -Username
        -Password
        -Email
        -Description
    
    
    Sign up
        -Validate that email or username does not already exist (grep file [sh])
        -Validate that the password is strong based on parameters (grep characters [sh])
            -Use pipes to read the output of the output shell scripts (output to [1] and read from [0])
        -Initialize blank description 
            -File Storing Cred Format -> |username-password|email-password| (write to file [c++])
    Login
        -Validate that email or username is in file along with maching password (grep file [sh])
        -Allow user to update password, username, and email [c++] based on strength (password) and not already in use (username, email) [sh]
        -Allow user to update description [c++]
    

