import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Stream;

public class Context {
	
	private Path fileDir;
	
	private List<PasswordPair> passwordPairs;
	
	private List<PasswordPair> acceptablePairs;

	public Context(String inputDir) {
		this.fileDir = Paths.get(inputDir);
		this.acceptablePairs = new ArrayList<PasswordPair>();
	}
	
	public void clearAcceptable() {
		this.acceptablePairs.clear();
	}

	public void read() {
		this.passwordPairs = new ArrayList<PasswordPair>();
		
		try (Stream<String> stream = Files.lines(fileDir)) {
			
			stream.forEach(str -> {
				String[] splt = str.split(":");
				
				Policy pol = new Policy(splt[0]);
				String pass = splt[1];
				
				passwordPairs.add(new PasswordPair(pol, pass));
			});
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
	}

	public Stream<PasswordPair> getPasswords() {
		return passwordPairs.stream();
	}

	public void addAcceptable(PasswordPair password) {
		acceptablePairs.add(password);
	}

	public List<PasswordPair> getAcceptablePasswords() {
		return acceptablePairs;
	}
}
