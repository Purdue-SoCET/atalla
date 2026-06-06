mods=$(ls master_modules_32/ | grep ".*alignTree_00110.*")

# Calculate the total number of modules by counting the words
total=$(echo "$mods" | wc -w)

# Initialize the counter
count=0

for mod in $mods; do 
    echo "Running shmoo for $mod"
    ./shmoo_generated_adders.sh "$mod"
    
    # Increment the counter
    ((count++))
    
    # Print the progress
    echo "$count / $total modules completed"
    echo "-----------------------------------" # Optional: adds visual separation
done

curl -d "shmoo_overnight done" ntfy.sh/karani-xbskdh-shmoo-alert
