
public class Main {
	
	public static void main(String[] args) {
		Context runtimeContext = GetContext("input.txt");
		runtimeContext.read();
		
		// PART 1
		oldValidatePasswords(runtimeContext);
		
		runtimeContext.clearAcceptable();
		
		// PART 2
		newValidatePasswords(runtimeContext);
	}
	
	public static Context GetContext(String inputDir) {
		return new Context(inputDir);
	}
	
	public static void oldValidatePasswords(Context cont) {
		
		cont.getPasswords().forEach(password -> {
			int counter = 0;
			
			for(char x : password.value.toCharArray()){ 
				if(x == password.policy.getExpectedCharacter()) {
					++counter;
				}
			}
			
			if(password.policy.isCountAcceptable(counter)) {
				cont.addAcceptable(password);
			}
		});
		
		System.out.println(cont.getAcceptablePasswords().size());
	}
	
	public static void newValidatePasswords(Context cont) {
		
		cont.getPasswords().forEach(password -> {
			
			int counter = 0;
			
			if(password.value.charAt(password.policy.getLower()) == password.policy.getExpectedCharacter()) {
				++counter;
			}
			
			if(password.value.charAt(password.policy.getUpper()) == password.policy.getExpectedCharacter()) {
				++counter;
			}
			
			if(counter == 1) {
				cont.addAcceptable(password);
			}
			
		});
		
		System.out.println(cont.getAcceptablePasswords().size());
	}
}
