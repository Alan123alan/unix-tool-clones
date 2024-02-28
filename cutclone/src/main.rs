use std::env;
use std::fs;


fn main() {
    let mut field: bool = false;
    let mut has_delimiter: bool = false;
    let args: Vec<String> = env::args().collect();
    //the file shoud always be the last argument
    let file_path = match args.last(){
        Some(arg)=>&arg[..],
        None=>"",
    };
    let file = fs::read_to_string(file_path);
    let mut file_contents: String = "".to_string();
    match file {
        Ok(contents)=>file_contents=contents,
        Err(error)=>{
            eprintln!("Error: {:#?}", error);
            std::process::exit(1)
        },
    }
    dbg!(file_contents);
    dbg!(&args);
    for arg in &args[1..]{//slicing the first argument since it is the program path
        //the first two characters from the argument need to be -<option_flag>
        //start by suporting -d and -f options
        //if any unsupported option flag is parsed exit the program with an error 
        //thrown error describes the first unsupported flag found
        let option_flag = &arg[..2];
        let option_value = &arg[2..];
        match option_flag {
            "-f"=>field = true,
            "-d"=>{
                has_delimiter = true;
            },
            _=>{
                eprintln!("Unrecognized flag {}", arg);
                std::process::exit(1);
            },
        }
    }
    dbg!(field);
}
