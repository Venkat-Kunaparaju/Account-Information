# Account Information
 Funcationality
    User Information
        -Username
        -Password
        -Email
    
    
    Sign up
        -Validate that email and username does not already exist (grep file [sh])
        -Validate that the password is strong based on parameters (grep characters [sh])
            -Use pipes to read the output of the output shell scripts (output to [1] and read from [0])
            -File Storing Cred Format -> |username-password|email-password| (write to file [c++])
    Login
        -Validate that email or username is in file along with maching password (grep file [sh])
        -Allow user to update password, username, and email [c++] based on strength (password) and not already in use (username, email) [sh]
    

