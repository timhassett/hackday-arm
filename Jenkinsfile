@Library('ciinabox') _

pipeline {
  triggers {
      bitbucketPush()
  }

  environment {
    AWS_REGION = 'ap-southeast-2'
    OPS_ACCOUNT_ID = 'xxxxxxx'
    SOURCE_BUCKET = 'source.tools'
    PROJECT_NAME = 'hackday-arm' //Can't use dots (.) in cloudformation stackname
  }

  agent {
            dockerfile {
                filename 'Dockerfile.build'
                reuseNode true
            }
        }
  
  stages {

    stage('build') {
        
        parallel {
            stage("build x86") {
                steps {
                    sh "g++ hello.cpp -o hello-x86"
                    sh "g++ primes.cpp -o primes-x86"
                }
            }
            stage("build arm") {
                steps {
                    sh "aarch64-linux-gnu-g++ hello.cpp -o hello-arm"
                    sh "aarch64-linux-gnu-g++ primes.cpp -o primes-arm"
                }
            }
        }
    }
    stage('publish') {
        steps {
            sh "aws s3 cp hello-x86 s3://hackday-tim-jhkdsgbfjksdbfjksdbf3/binaries/hello-x86 --no-sign-request"
            sh "aws s3 cp hello-arm s3://hackday-tim-jhkdsgbfjksdbfjksdbf3/binaries/hello-arm --no-sign-request"
            sh "aws s3 cp primes-x86 s3://hackday-tim-jhkdsgbfjksdbfjksdbf3/binaries/primes-x86 --no-sign-request"
            sh "aws s3 cp primes-arm s3://hackday-tim-jhkdsgbfjksdbfjksdbf3/binaries/primes-arm --no-sign-request"
        }
    }
  }

}
