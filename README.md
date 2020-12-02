# NetApp Trident Audit Tool

This tool is meant to test the validity of running NetApp Trident in production.  It is based on Facebook's nfusr, a user space NFS client that can directly talk to an NFS server and access it's exports.

## Usage

This utility is designed to run in Kubernetes.  You must have NetApp Trident already configured and enabled.  

To run this utility, you simply edit the provided `nfstest.yaml` Kubernetes POD spec.  Change the NFS server IP address to point to your NetApp.

Substitute the PVC in the yaml with an existing Trident NAS PVC.

Then run `kubectl apply -f nfstest.yaml`

### Tests

Data Vulnerability Test: See if the POD can access other PVCs:
```
# kubectl exec -it <nfstest-POD> -- bash
# cd /data
# ls
```
If you can see the PVC's contents, then this demonstrates that this POD can succesfully access a PVC from some other deployment, without even having been granted that PVC via Kubernetes.  This would demonstrate a serious security flaw.


## Building

To build from source:

    ./bootstrap
    ./configure
    make

To build a container, modify the provided `build_container.sh` to point to your repository.

## License

nfusr is BSD-licensed.
