import java.io.RandomAccessFile;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;

public class SharedMemoryIPC {

    private static final String FILE_NAME = "shared_memory.dat";

    public static void main(String[] args) throws Exception {
        // Create/open a file
        RandomAccessFile file = new RandomAccessFile(FILE_NAME, "rw");
        FileChannel channel = file.getChannel();

        // Map 1024 bytes of the file into memory
        MappedByteBuffer sharedMemory =
            channel.map(FileChannel.MapMode.READ_WRITE, 0, 1024);

        // Process 1 writes data to shared memory
        String message = "Hello from Process 1!";
        sharedMemory.put(message.getBytes());
        System.out.println("Process 1 wrote: " + message);

        // Reset position to read the data
        sharedMemory.position(0);

        // Process 2 reads data from shared memory
        byte[] data = new byte[message.length()];
        sharedMemory.get(data);
        String receivedMessage = new String(data);
        System.out.println("Process 2 read: " + receivedMessage);

        // Close resources
        channel.close();
        file.close();
    }
}
